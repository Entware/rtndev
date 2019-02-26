#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# No longer maintained. Origin was removed according to regulations.

include $(TOPDIR)/rules.mk

PKG_NAME:=shadowvpn
PKG_VERSION:=0.2.0
PKG_RELEASE:=2

PKG_SOURCE:=ShadowVPN-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/aa65535/openwrt-shadowvpn/releases/download/v0.2.0
PKG_HASH:=53b445cf47262f407bfef72d32bc6ca5d1341dcd3878ac2b4cd35ee030199dea

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

PKG_BUILD_DIR:=$(BUILD_DIR)/ShadowVPN-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/shadowvpn
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	DEPENDS:=+libsodium
	TITLE:=ShadowVPN
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shadowvpn/description
 ShadowVPN is a fast, safe VPN based on libsodium.
endef

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
	$(INSTALL_CONF) ./files/{server,client}.conf $(1)/opt/etc/shadowvpn
	$(INSTALL_BIN) ./files/{server,client}{_up.sh,_down.sh} $(1)/opt/etc/shadowvpn
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S20shadowvpn-client $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,shadowvpn))
