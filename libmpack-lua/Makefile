# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2026 Entware
#
# only build host library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=libmpack-lua
PKG_VERSION:=1.0.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/libmpack/libmpack-lua/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=436a6a3973207403d3f20082002c32e74c25d9149ff2516dc06b0b41514044bf

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE-MIT

PKG_HOST_ONLY:=1
HOST_BUILD_DEPENDS:=lua/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/host-build.mk

define Package/libmpack-lua
	SUBMENU:=Lua
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=libmpack lua binding
	URL:=https://github.com/libmpack/libmpack-lua
	MAINTAINER:=Entware team, https://entware.net
	BUILDONLY:=1
endef

define Package/libmpack-lua/description
  Lua binding to libmpack.
endef

Host/Configure:=:

define Host/Install
	$(INSTALL_DIR) $(STAGING_DIR_HOSTPKG)/lib/lua/5.1
	$(INSTALL_BIN) $(HOST_BUILD_DIR)/mpack.so $(STAGING_DIR_HOSTPKG)/lib/lua/5.1
endef

$(eval $(call BuildPackage,libmpack-lua))
$(eval $(call HostBuild))
