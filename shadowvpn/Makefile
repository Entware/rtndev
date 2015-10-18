#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Based on https://github.com/clowwindy/ShadowVPN/blob/master/openwrt/Makefile
# TO DO: use external libsodium after upgrading it up to 1.0.2

include $(TOPDIR)/rules.mk

PKG_NAME:=shadowvpn
PKG_VERSION:=0.1.6-20150721
PKG_REV:=25761e971d3af1009cc29c644f0e18142045c39e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/clowwindy/ShadowVPN
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/shadowvpn
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	TITLE:=ShadowVPN
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/shadowvpn/description
 ShadowVPN is a fast, safe VPN based on libsodium.
endef

CONFIGURE_ARGS += \
	--disable-ssp \
	--disable-asm \

define Package/shadowvpn/conffiles
/opt/etc/shadowvpn/server.conf
/opt/etc/shadowvpn/server_up.sh
/opt/etc/shadowvpn/server_down.sh
/opt/etc/shadowvpn/client.conf
/opt/etc/shadowvpn/client_up.sh
/opt/etc/shadowvpn/client_down.sh
endef

define Package/shadowvpn/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/etc/shadowvpn
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/shadowvpn/{server,client}{.conf,_up.sh,_down.sh} \
	    $(1)/opt/etc/shadowvpn
	$(INSTALL_BIN) ./files/S20shadowvpn-client $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/shadowvpn $(1)/opt/bin
endef

$(eval $(call BuildPackage,shadowvpn))
