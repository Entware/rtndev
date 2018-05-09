#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from
# http://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=ubuntu-font-family
PKG_VERSION:=0.83
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_URL:=http://font.ubuntu.com/download
PKG_HASH:=456d7d42797febd0d7d4cf1b782a2e03680bb4a5ee43cc9d06bda172bac05b42

include $(INCLUDE_DIR)/package.mk

define Package/ubuntu-fonts
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+fontconfig
	TITLE:=ubuntu-fonts
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ubuntu-fonts/description
 The Ubuntu typeface has been specially created to complement the Ubuntu tone of
 voice. It has a contemporary style and contains characteristics unique to the
 Ubuntu brand that convey a precise, reliable and free attitude.
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/ubuntu-fonts/install
	$(INSTALL_DIR) $(1)/opt/share/fonts/ubuntu
	$(CP) $(PKG_BUILD_DIR)/*.ttf $(1)/opt/share/fonts/ubuntu

endef

define Package/ubuntu-fonts/postinst
#!/bin/sh
/opt/bin/fc-cache --force --verbose
endef

$(eval $(call BuildPackage,ubuntu-fonts))
