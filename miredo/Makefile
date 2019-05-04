#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=miredo
PKG_VERSION:=1.2.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://www.remlab.net/files/miredo
PKG_HASH:=fa26d2f4a405415833669e2e2e22677b225d8f83600844645d5683535ea43149

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/miredo
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=@IPV6 +libcap +ip-full
	TITLE:=Teredo IPv6 tunneling software
	URL:=https://www.remlab.net/miredo/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/miredo/description
 Miredo is an open-source Teredo IPv6 tunneling software. It includes
 functional implementations of all components of the Teredo specification
 (client, relay and server). It is meant to provide IPv6 connectivity even from
 behind NAT devices.
endef

CONFIGURE_VARS += \
	ac_cv_file__proc_self_maps=yes

CONFIGURE_ARGS += \
	--disable-static \
	--disable-binreloc \
	--disable-assert

define Package/miredo/conffiles
/opt/etc/miredo
endef

define Package/miredo/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/teredo-mire $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/etc $(1)/opt
	$(INSTALL_DIR) $(1)/opt/lib/miredo
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/miredo/miredo-privproc \
		$(1)/opt/lib/miredo
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/miredo* $(1)/opt/sbin
endef

$(eval $(call BuildPackage,miredo))
