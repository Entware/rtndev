#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=minissdpd
PKG_VERSION:=2.2.2
PKG_REV:=81029a860baf1f727903e5b85307903b3f40cbc8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/miniupnp/miniupnp.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

MAKE_PATH:=$(PKG_NAME)

define Package/minissdpd
	SECTION:=net
	CATEGORY:=Network
	 DEPENDS:=+libnfnetlink
	TITLE:=SSDP daemon
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/minissdpd/description
 MiniSSDPd is a daemon that:
 1 - keeps track of all UPnP devices announcing themselves on the network.
 its database can be queried by local processes using a protocol based on
 a unix socket. That enables local processes to quickly discover UPnP devices
 without broadcasting SSDP message and waiting several seconds for a response.
 2 - keeps a database of local UPnP devices hosted on the machine and
 answering SSDP searchs on their behalf. It enables to run several UPnP devices,
 like an IGD and a MediaServer, on the same machine.
endef

define Package/gnuchess/conffiles
/opt/etc/config/minissdpd.conf
endef

define Package/minissdpd/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME)/$(PKG_NAME) $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S11minissdpd $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/etc/config
	$(INSTALL_CONF) files/minissdpd.conf $(1)/opt/etc/config
endef

$(eval $(call BuildPackage,minissdpd))
