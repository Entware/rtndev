# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=airsane
PKG_VERSION:=0.4.12
PKG_REV:=129cc3bf7258251a0a694dee7741285b59d88f9f
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/SimulPiscator/AirSane.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1675f066e53f218319a1a634f751af4b4a3c9f5527d0641863c62eef553b9e8d

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
