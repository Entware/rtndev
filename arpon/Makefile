#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=arpon
PKG_VERSION:=3.0-ng
PKG_RELEASE:=1

PKG_SOURCE:=ArpON-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/arpon
PKG_HASH:=ea55d1641b4573b19103ca596368e418aecd2a1409adbdce3a9f76dc8ebad590

PKG_BUILD_DIR:=$(BUILD_DIR)/ArpON-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/arpon
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libnet-1.2.x +libdnet
	TITLE:=ARP handler inspector
	URL:=http://arpon.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/arpon/description
 ArpON (ARP handler inspection) is a Host-based solution that make the ARP
 standardized protocol secure in order to avoid the Man In The Middle (MITM)
 attack through the ARP spoofing, ARP cache poisoning or ARP poison routing
 attack.
endef

define Package/arpon/conffiles
/opt/etc/arpon.conf
endef

define Package/arpon/install
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/arpon.conf $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/arpon $(1)/opt/sbin
endef

$(eval $(call BuildPackage,arpon))
