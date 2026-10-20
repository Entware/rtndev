# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=airsane
PKG_VERSION:=0.4.15
PKG_REV:=ac117f185e06afc7c3557f9839a42d8fd9fd18fa
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/SimulPiscator/AirSane.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=7bc4b1e193e03d4c36a6543b2c7bb56741174e119967fea78c16e0993b98368e

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/airsane
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libavahi-client +sane-libs
	TITLE:=AirScan Scanner publisher
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/airsane/description
 Publish SANE scanners to MacOS and Android via Apple AirScan.
endef

define Package/airsane/conffiles
/opt/etc/airsane/access.conf
/opt/etc/airsane/ignore.conf
/opt/etc/airsane/options.conf
/opt/etc/config/airsaned.conf
endef

define Package/airsane/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/airsaned $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/airsane
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/airsane/*.conf $(1)/opt/etc/airsane
	$(INSTALL_DIR) $(1)/opt/etc/config
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/default/airsane $(1)/opt/etc/config/airsaned.conf
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S43airsaned $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,airsane))
