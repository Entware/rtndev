#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the last version without G_SockList objects

include $(TOPDIR)/rules.mk

PKG_NAME:=ngrok-c
PKG_VERSION:=1.45-20180507
PKG_REV:=990efc7efa325689697c2bc3807f5753a39d74b7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/dosgo/ngrok-c.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/ngrok-c
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+libopenssl +libstdcpp
	TITLE:=ngrok client for C language
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ngrok-c/description
 ngrok client written in C.
endef

define Package/ngrok-c/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/ngrokc $(1)/opt/sbin
endef

$(eval $(call BuildPackage,ngrok-c))
