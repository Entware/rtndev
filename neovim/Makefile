#
# Copyright (C) 2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=neovim
PKG_VERSION:=0.9.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/neovim/neovim/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=39d79107c54d2f3babcad2cd157c399241c04f6e75e98c18e8afaf2bb5e82937

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE.txt

PKG_BUILD_DEPENDS:=libmpack-lua/host lpeg/host lua/host luabitop/host
PKG_BUILD_DEPENDS+=libtermkey libvterm tree-sitter unibilium

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/neovim
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Editors
  TITLE:=hyperextensible Vim-based text editor
  URL:=https://neovim.io
  PKG_MAINTAINER:=Entware team, https://entware.net
  DEPENDS:=+libncursesw +luajit +luv +msgpack-c $(ICONV_DEPENDS) $(INTL_DEPENDS)
endef

define Package/neovim/description
  Vim-fork focused on extensibility and usability.
endef

CMAKE_BINARY_SUBDIR:=build

TARGET_CFLAGS += -pthread
TARGET_LDFLAGS += -lncursesw

# XXX fake tags
define FixPreCompile
	touch $(PKG_BUILD_DIR)/runtime/doc/tags
endef

Hooks/Compile/Pre += FixPreCompile

define Package/neovim/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/nvim $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/nvim
	$(CP) $(PKG_INSTALL_DIR)/opt/share/nvim/runtime $(1)/opt/share/nvim
endef

define Package/neovim/postinst
#!/bin/sh

DIR="/opt/share/nvim/runtime"

echo "Generating tags..."

nvim -u NONE -i NONE -e --headless -c "helptags ++t $$DIR/doc" -c quit
nvim -u NONE -i NONE -e --headless -c "helptags $$DIR/pack/dist/opt/matchit/doc" -c quit
nvim -u NONE -i NONE -e --headless -c "helptags $$DIR/pack/dist/opt/vimball/doc" -c quit
endef

$(eval $(call BuildPackage,neovim))
