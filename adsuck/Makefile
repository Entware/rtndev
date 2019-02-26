#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=adsuck
PKG_VERSION:=2.5.0
PKG_REV:=f7822a2a3951542d130bca0bc7298ce47504dcdd
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/conformal/adsuck.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/adsuck
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	DEPENDS:=+libldns +libevent2
	TITLE:=adsuck is a small DNS server that spoofs blacklisted addresses
	URL:=https://opensource.conformal.com/wiki/adsuck
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/adsuck/description
 adsuck is a small DNS server that spoofs blacklisted addresses and forwards
 all other queries. The idea is to be able to prevent connections
 to undesirable sites such as ad servers, crawlers and other nasties.
endef

define Package/adsuck/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/adsuck $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/adsuck
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/files/*  $(1)/opt/etc/adsuck
endef

$(eval $(call BuildPackage,adsuck))
