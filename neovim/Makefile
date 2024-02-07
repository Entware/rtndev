# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=neovim
PKG_VERSION:=0.9.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/neovim/neovim/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=fe74369fc30a32ec7a086b1013acd0eacd674e7570eb1acc520a66180c9e9719

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
  DEPENDS:=+libncursesw @HAS_LUAJIT_ARCH +luajit +luv +msgpack-c $(ICONV_DEPENDS) $(INTL_DEPENDS)
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
