# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=rtp2httpd
PKG_VERSION:=3.17.1
PKG_RELEASE:=1
PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=LICENSE

PKG_SOURCE:=$(PKG_NAME)-v$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/stackia/rtp2httpd/tar.gz/v$(PKG_VERSION)?
PKG_HASH:=80a79f148f8a6fc412dcfe2d45b4b552869a4a98f21b3128eafe75933580a740

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

CMAKE_OPTIONS += \
	-DPROJECT_VERSION_STRING="$(PKG_VERSION)" \
	-DENABLE_AGGRESSIVE_OPT=ON

define Package/rtp2httpd
	SECTION:=net
	CATEGORY:=Network
	TITLE:=Multicast RTP/RTSP to Unicast HTTP stream converter, optimized for China IPTV
	URL:=https://github.com/stackia/rtp2httpd
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rtp2httpd/description
	rtp2httpd converts RTP/UDP/RTSP media into http stream.
	It acts as a tiny HTTP server. When client connect,
	pre-configured multicast RTP service is choosen by URL.
	Program then join pre-configured multicast address and translate
	incoming RTP data to HTTP stream.
endef

define Package/rtp2httpd/conffiles
/opt/etc/rtp2httpd.conf
endef

define Package/rtp2httpd/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d $(1)/opt/etc $(1)/opt/bin
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/rtp2httpd.conf $(1)/opt/etc
	$(INSTALL_BIN) ./files/S29rtp2httpd $(1)/opt/etc/init.d
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/rtp2httpd $(1)/opt/bin
endef

$(eval $(call BuildPackage,rtp2httpd))
