#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=shadowvpn
PKG_VERSION:=0.2.0
PKG_REV:=d96833ce07098f93065182e497b771e035d07df8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/GFW-Fucker/ShadowVPN.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/shadowvpn
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	DEPENDS:=+libsodium
	TITLE:=ShadowVPN
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, entware.net
endef

define Package/shadowvpn/description
 ShadowVPN is a fast, safe VPN based on libsodium.
endef

CONFIGURE_ARGS += \
	--disable-ssp \
	--disable-asm \
	--enable-minimal

define Package/shadowvpn/conffiles
/opt/etc/shadowvpn/server.conf
/opt/etc/shadowvpn/server_up.sh
/opt/etc/shadowvpn/server_down.sh
/opt/etc/shadowvpn/client.conf
/opt/etc/shadowvpn/client_up.sh
/opt/etc/shadowvpn/client_down.sh
endef

define Package/shadowvpn/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/shadowvpn $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libshadowvpn.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/etc/shadowvpn
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/shadowvpn/{server,client}{.conf,_up.sh,_down.sh} \
	    $(1)/opt/etc/shadowvpn
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S20shadowvpn-client $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,shadowvpn))
