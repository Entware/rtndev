#
# Copyright (C) 2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# only build host library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=libmpack-lua
PKG_VERSION:=1.0.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/libmpack/libmpack-lua/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=b58a25a0b48e1ec584beee6c80e0e31182dad7a45005ce58e88e6cfff3a3f3e4

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
