# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=xupnpd2
PKG_VERSION:=2.0-20231215
PKG_REV:=9dc123d7e034b338ef5824c390d1b4ae8b2cf639
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/clark15b/xupnpd2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=b1058f14081ee3b0c9c6e5705dd0de8f52b04199c4a92fa9942e7afb5f255f1e

include $(INCLUDE_DIR)/package.mk

define Package/xupnpd2
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libsqlite3 +liblua5.3 +libuuid +libstdcpp +libopenssl
	TITLE:=eXtensible UPnP agent
	URL:=https://github.com/clark15b/xupnpd2
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/xupnpd2/description
 This program is a light DLNA Media Server which provides ContentDirectory:1
 service for sharing IPTV unicast streams over local area network (with udpxy
 for multicast to HTTP unicast conversion). The program shares UTF8-encoded M3U
 playlists with links over local area network as content of the directory.
 You can watch HDTV broadcasts (multicast or unicast) and listen Internet
 Radio in IP network without transcoding and PC.
endef


define Package/xupnpd2/conffiles
/opt/etc/xupnpd2/xupnpd.cfg
/opt/etc/xupnpd2/xupnpd.lua
endef

define Build/Configure
	echo 'include build/rules.mk' > $(PKG_BUILD_DIR)/Makefile
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include/lua5.3

TARGET_LDFLAGS += -ldl -luuid -lsqlite3 -llua5.3 -lssl -lcrypto


define Package/xupnpd2/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/xupnpd $(1)/opt/sbin/xupnpd2
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S94xupnpd2 $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/etc/xupnpd2
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/xupnpd.{cfg,lua} $(1)/opt/etc/xupnpd2
	$(INSTALL_DIR) $(1)/opt/share/xupnpd2/media
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/media/example.m3u \
		$(1)/opt/share/xupnpd2/media
	$(CP) $(PKG_BUILD_DIR)/www $(1)/opt/share/xupnpd2
endef

$(eval $(call BuildPackage,xupnpd2))
