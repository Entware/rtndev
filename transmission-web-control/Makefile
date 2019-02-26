#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=transmission-web-control
PKG_VERSION:=1.6.0-beta2
PKG_REV:=d2e2fd185ed052d5b88eb0ec0755a46fb4910be6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/ronggang/transmission-web-control.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/transmission-web-control
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=BitTorrent
	TITLE:=Transmissionbt custom web UI
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/transmission-web-control/description
 Transmission Web Control is a custom web UI.
endef

define Build/Compile
endef

define Package/transmission-web-control/install
	$(INSTALL_DIR) $(1)/opt/share/transmission/web
	$(CP) $(PKG_BUILD_DIR)/src/* $(1)/opt/share/transmission/web
endef

$(eval $(call BuildPackage,transmission-web-control))
