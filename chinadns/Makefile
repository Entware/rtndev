#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=chinadns
PKG_VERSION:=1.3.2-20150812
PKG_REV:=9e4261c78e911851f76a9b9113d48fcdc44ce32e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/shadowsocks/ChinaDNS.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/chinadns
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=IP Addresses and Names
	TITLE:=a tool to bypass DNS poisoning
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/chinadns/description
 Traditional way to bypass DNS poisoning is to send all queries to a foreign
 DNS server via VPN. However some Chinese websites will get bad results if they
 have CDNs outside the country.
endef

define Package/chinadns/conffiles
/opt/etc/chinadns_iplist.txt
/opt/etc/chinadns_chnroute.txt
endef

define Package/chinadns/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/share/chnroute.txt \
		$(1)/opt/etc/chinadns_chnroute.txt
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/share/iplist.txt \
		$(1)/opt/etc/chinadns_iplist.txt
	$(INSTALL_BIN) ./files/S56chinadns $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/chinadns $(1)/opt/bin
endef

$(eval $(call BuildPackage,chinadns))
