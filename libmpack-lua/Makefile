#
# Copyright (C) 2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# only build static library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=libmpack-lua
PKG_VERSION:=1.0.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/libmpack/libmpack-lua/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=e94d5cf95d7479dca00ff23755fe05a440f11f9d203635e862ad8842de95f40a

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
  PKG_MAINTAINER:=Entware team, https://entware.net
  DEPENDS:=+lua
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

Build/Configure:=:

define Package/libmpack-lua/install
	$(INSTALL_DIR) $(1)/opt/lib/lua
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mpack.so $(1)/opt/lib/lua
endef

$(eval $(call BuildPackage,libmpack-lua))
$(eval $(call HostBuild))
