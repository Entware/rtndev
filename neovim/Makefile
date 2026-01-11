# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=neovim
PKG_VERSION:=0.11.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/neovim/neovim/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=c63450dfb42bb0115cd5e959f81c77989e1c8fd020d5e3f1e6d897154ce8b771

PKG_LICENSE:=Apache-2.0
PKG_LICENSE_FILES:=LICENSE.txt

PKG_BUILD_DEPENDS:=libffi/host lua/host lua-ffi/host luabitop/host
PKG_BUILD_DEPENDS+=liblpeg tree-sitter unibilium utf8proc

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
  DEPENDS:=+libncursesw +libuv +luajit +luv @HAS_LUAJIT_ARCH $(INTL_DEPENDS)
endef

define Package/neovim/description
  Vim-fork focused on extensibility and usability.
endef

CMAKE_BINARY_SUBDIR:=build-cross

TARGET_CFLAGS += -pthread
TARGET_LDFLAGS += -lncursesw

define BuildDeps
	( cd $(PKG_BUILD_DIR); \
		cmake -S cmake.deps -B .deps -G "Ninja" -DCMAKE_BUILD_TYPE=Release; \
		cmake --build .deps -j$(NPROC); \
	)
endef

define BuildNativeBins
	( cd $(PKG_BUILD_DIR); \
		cmake -B build-native -G "Ninja" -DCMAKE_BUILD_TYPE=Release; \
		cmake --build build-native -j$(NPROC); \
		$(CP) $(PKG_BUILD_DIR)/build-native/lib/libnlua0.so \
			$(STAGING_DIR_HOSTPKG)/lib/lua/5.1/nlua0.so; \
	)
endef

define BuildParsers
	( cd $(PKG_BUILD_DIR); $(INSTALL_DIR) .deps-cross; \
		CC=$(TARGET_CC) CFLAGS="$(TARGET_CFLAGS)" \
		$(MAKE) -C .deps-cross \
		BUNDLED_CMAKE_FLAG="\
			-DCMAKE_BUILD_TYPE=Release \
			-DUSE_BUNDLED=OFF \
			-DUSE_BUNDLED_LIBUV=ON \
			-DUSE_BUNDLED_LPEG=ON \
			-DUSE_BUNDLED_LUAJIT=OFF \
			-DUSE_BUNDLED_LUA=ON \
			-DUSE_BUNDLED_LUV=ON \
			-DUSE_BUNDLED_TS=ON \
			-DUSE_BUNDLED_TS_PARSERS=ON \
			-DUSE_BUNDLED_UNIBILIUM=ON \
			-DUSE_BUNDLED_UTF8PROC=ON" \
		-f ../Makefile deps; \
	)
endef

define Build/Compile
	$(call BuildDeps)
	$(call BuildNativeBins)
	$(call BuildParsers)
endef

define Package/neovim/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/nvim $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/nvim/parser
	$(CP) \
		$(PKG_BUILD_DIR)/.deps-cross/.deps/usr/lib/nvim/parser/*.so \
			$(1)/opt/lib/nvim/parser
	$(INSTALL_DIR) $(1)/opt/share/nvim
	$(CP) $(PKG_INSTALL_DIR)/opt/share/nvim/runtime $(1)/opt/share/nvim
endef

$(eval $(call BuildPackage,neovim))
