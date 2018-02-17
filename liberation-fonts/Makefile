#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=liberation-fonts-ttf
PKG_VERSION:=2.00.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://releases.pagure.org/liberation-fonts
PKG_HASH:=7890278a6cd17873c57d9cd785c2d230d9abdea837e96516019c5885dd271504

include $(INCLUDE_DIR)/package.mk

define Package/liberation-fonts
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+fontconfig
	TITLE:=ghostscript, standard fonts
	URL:=https://fedorahosted.org/liberation-fonts/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/liberation-fonts/description
 The Liberation(tm) Fonts is a font family which aims at metric compatibility
 with Arial, Times New Roman, and Courier New. It is sponsored by Red Hat
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/liberation-fonts/install
	$(INSTALL_DIR) $(1)/opt/share/fonts/truetype/liberation
	$(CP) $(PKG_BUILD_DIR)/*.ttf $(1)/opt/share/fonts/truetype/liberation

endef

define Package/liberation-fonts/postinst
#!/bin/sh
/opt/bin/fc-cache --force --verbose
endef

$(eval $(call BuildPackage,liberation-fonts))
