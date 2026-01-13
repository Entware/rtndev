# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=wg-quick
PKG_VERSION:=1.0.20250521
PKG_RELEASE:=1

PKG_SOURCE:=wireguard-tools-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://git.zx2c4.com/wireguard-tools/snapshot
PKG_HASH:=b6f2628b85b1b23cc06517ec9c74f82d52c4cdbd020f3dd2f00c972a1782950e

include $(INCLUDE_DIR)/package.mk

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_UNPACK:= $(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

define Package/wg-quick
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=VPN
	URL:=https://www.wireguard.com
	MAINTAINER:=Jason A. Donenfeld <Jason@zx2c4.com>
	TITLE:=WireGuard wg-quick script
	DEPENDS:=+bash +coreutils-stat @!LINUX_2_6_36
	PKGARCH:=all
endef

define Package/wg-quick/description
 This is an extremely simple script for easily bringing up a WireGuard
 interface, suitable for a few common use cases.
endef

define Build/Compile
endef

define Package/wg-quick/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/wg-quick/linux.bash $(1)/opt/bin/wg-quick
endef

$(eval $(call BuildPackage,wg-quick))
