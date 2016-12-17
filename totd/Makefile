#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=totd
PKG_VERSION:=1.5.2
PKG_REV:=afd8a10a6a21f82a70940d1b43cff48143250399
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/fwdillema/totd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/totd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	TITLE:=DNS proxy and translator for IPv6 and IPv4
	URL:=https://github.com/fwdillema/totd
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/totd/description
 DNS proxy and translator for IPv6 and IPv4.
endef

define Package/totd/conffiles
/opt/etc/totd.conf
endef

define Package/totd/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/totd $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/totd.conf.sample $(1)/opt/etc/totd.conf
	$(INSTALL_BIN) ./files/S57totd $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,totd))
