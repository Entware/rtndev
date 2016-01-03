#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=adsuck
PKG_VERSION:=2.5.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://opensource.conformal.com/snapshots/adsuck/
PKG_MD5SUM:=f8e442da00e9364002de177352a5e302

include $(INCLUDE_DIR)/package.mk

define Package/adsuck
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	DEPENDS:=+libldns +libevent2
	TITLE:=adsuck is a small DNS server that spoofs blacklisted addresses
	URL:=https://opensource.conformal.com/wiki/adsuck
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/adsuck/description
 adsuck is a small DNS server that spoofs blacklisted addresses and forwards
 all other queries. The idea is to be able to prevent connections
 to undesirable sites such as ad servers, crawlers and other nasties.
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(STAGING_DIR)/opt/include -D_GNU_SOURCE -D_BSD_SOURCE -o $(PKG_BUILD_DIR)/adsuck.o $(PKG_BUILD_DIR)/adsuck.c
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(STAGING_DIR)/opt/include -D_GNU_SOURCE -D_BSD_SOURCE -o $(PKG_BUILD_DIR)/log.o $(PKG_BUILD_DIR)/log.c
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(STAGING_DIR)/opt/include -D_GNU_SOURCE -D_BSD_SOURCE -o $(PKG_BUILD_DIR)/linux/strlcpy.o $(PKG_BUILD_DIR)/linux/strlcpy.c
	$(TARGET_CC) $(TARGET_CFLAGS) -c -I$(STAGING_DIR)/opt/include -D_GNU_SOURCE -D_BSD_SOURCE -o $(PKG_BUILD_DIR)/resolv.o $(PKG_BUILD_DIR)/resolv.c
	$(TARGET_CC) $(TARGET_LDFLAGS) -L$(STAGING_DIR)/opt/lib -o $(PKG_BUILD_DIR)/adsuck \
		$(PKG_BUILD_DIR)/adsuck.o \
		$(PKG_BUILD_DIR)/log.o \
		$(PKG_BUILD_DIR)/linux/strlcpy.o \
		$(PKG_BUILD_DIR)/resolv.o \
		-lldns -levent
endef

define Package/adsuck/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/adsuck $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/adsuck
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/files/*  $(1)/opt/etc/adsuck
endef

$(eval $(call BuildPackage,adsuck))
