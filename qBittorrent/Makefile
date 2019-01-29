#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# ported to Entware from https://github.com/KryptonLee/qBittorrent-openwrt-package


include $(TOPDIR)/rules.mk

PKG_NAME:=qBittorrent
PKG_VERSION:=4.1.5
PKG_RELEASE=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/qbittorrent/qBittorrent.git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=3f0e0a319a6f4833b238842744ed1f37104fcd4c
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

PKG_LICENSE:=GPL-2.0+
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1
PKG_USE_MIPS16:=0

include $(INCLUDE_DIR)/package.mk

define Package/qBittorrent
  SUBMENU:=BitTorrent
  SECTION:=net
  CATEGORY:=Network
  TITLE:=bittorrent client programmed in C++ / Qt
  URL:=https://www.qbittorrent.org/
  DEPENDS:=+qt5-core +qt5-network +qt5-xml +rblibtorrent
endef

define Package/qBittorrent/description
qBittorrent is a bittorrent client programmed in C++ / Qt that uses 
libtorrent (sometimes called libtorrent-rasterbar) by Arvid Norberg.
It aims to be a good alternative to all other bittorrent clients out 
there. qBittorrent is fast, stable and provides unicode support as 
well as many features.
endef

CONFIGURE_VARS += \
	QT_QMAKE="$(TOOLCHAIN_DIR)/bin" \
	PKG_CONFIG_PATH="$(TOOLCHAIN_DIR)/lib/pkgconfig"

CONFIGURE_ARGS += \
	--disable-gui \
	--with-boost=$(STAGING_DIR)/opt

MAKE_VARS += \
	INSTALL_ROOT="$(PKG_INSTALL_DIR)"

define Package/qBittorrent/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/etc/init.d
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/qbittorrent-nox $(1)/opt/bin
	$(INSTALL_BIN) files/S89qBittorrent $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,qBittorrent))
