# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2025 Entware
#
# ported to Entware from https://github.com/KryptonLee/qBittorrent-openwrt-package
# This is the last version with Qt5 support

include $(TOPDIR)/rules.mk

PKG_NAME:=qbittorrent
PKG_VERSION:=4.6.7
PKG_REV:=839bc696d066aca34ebd994ee1673c4b2d5afd7b
PKG_RELEASE=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/qbittorrent/qbittorrent.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=c91463a863ad0ab00be95744c0c166f895a07cd864e5de2a4372b165bde5155b

PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_FLAGS:=no-mips16

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/qbittorrent
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=BitTorrent
	DEPENDS:=+libtorrent-rasterbar +qt5-network +qt5-sql +qt5-xml $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=bittorrent client programmed in C++ / Qt
	URL:=https://www.qbittorrent.org/
	PROVIDES:=qBittorrent
endef

define Package/qbittorrent/description
 qBittorrent is a bittorrent client programmed in C++ / Qt that uses
 libtorrent (sometimes called libtorrent-rasterbar) by Arvid Norberg.
 It aims to be a good alternative to all other bittorrent clients out
 there. qBittorrent is fast, stable and provides unicode support as
 well as many features.
endef

TARGET_CXXFLAGS += -pthread
TARGET_LDFLAGS += -latomic -lpthread

CMAKE_OPTIONS += \
	-DGUI=OFF \
	-DSTACKTRACE=OFF

define Package/qbittorrent/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/etc/init.d
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/qbittorrent-nox $(1)/opt/bin
	$(INSTALL_BIN) files/S89qbittorrent $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,qbittorrent))
