# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware
#
include $(TOPDIR)/rules.mk

PKG_NAME:=pingu
PKG_VERSION:=1.5.1
PKG_REV:=9dc7220c92a759a65840c6014d7c31f2d0cd9c55
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ncopa/pingu.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8070b99ca4dbdffea17fbb480d0f3e377bf85554c8f9ae9bc5346b55ed899e32

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/pingu
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libev
	TITLE:=policy routing daemon with failover
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pingu/description
 Pingu is a daemon that takes care of policy routing and fail-over
 in multi ISP setups. Support for DHCP, PPP, ISP failover, Load-balancing
 (nexthop), optional route rule based on fwmark, run script when ISP
 goes up/down.
endef

CONFIGURE_ARGS:= \
	--prefix=/opt \
	--disable-doc

TARGET_CFLAGS += $(FPIC)

define Package/pingu/conffiles
/opt/etc/pingu.conf
endef

define Package/pingu/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mtu $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/pingu{,ctl} $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/pingu.conf $(1)/opt/etc
	$(INSTALL_BIN) files/S11pingu $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,pingu))
