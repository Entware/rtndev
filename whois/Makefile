#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=whois
PKG_VERSION:=5.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://ftp.debian.org/debian/pool/main/w/whois
PKG_HASH:=4d789c403bfb5833c8ae168a5f31be70e34b045bd5d95a54c82a27b0ff135723

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/whois
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libidn
	TITLE:=intelligent WHOIS client
	URL:=http://ftp.debian.org/debian/pool/main/w/whois
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/whois/description
 This package provides a commandline client for the WHOIS (RFC 3912) protocol,
 which queries online servers for information such as contact details
 for domains and IP address assignments. It can intelligently select
 the appropriate WHOIS server for most queries.
endef

define Package/whois/conffiles
/opt/etc/whois.conf
endef

define Package/whois/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/whois $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/whois.conf $(1)/opt/etc/whois.conf
endef

$(eval $(call BuildPackage,whois))
