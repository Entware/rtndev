#
# Copyright (C) 2018-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by jq only

include $(TOPDIR)/rules.mk

PKG_NAME:=oniguruma
PKG_VERSION:=6.9.1
PKG_REV:=6a13239e0c5b55e1c55c1f9d27429343407383e4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/kkos/oniguruma.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/oniguruma
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=regular expression library
	URL:=https://github.com/kkos/oniguruma
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/oniguruma/description
 Oniguruma is a modern and flexible regular expressions library.
 It encompasses features from different regular expression implementations
 that traditionally exist in different languages.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/onig*.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libonig.so $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/oniguruma.pc $(1)/opt/lib/pkgconfig
endef

define Package/oniguruma/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libonig.so $(1)/opt/lib
endef

$(eval $(call BuildPackage,oniguruma))
