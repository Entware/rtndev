#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=castget
PKG_VERSION:=2.0.1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SAVANNAH/castget
PKG_HASH:=438b5f7ec7e31a45ed3756630fe447f42015acda53ec09202f48628726b5e875

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/castget
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libcurl +libstdcpp +glib2 +libxml2 +id3lib $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=a command-line podcast downloader
	URL:=http://johndal.com/castget
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/castget/description
 castget is a simple, command-line based RSS enclosure downloader.
 It is primarily intended for automatic, unattended downloading of podcasts.
endef

define Package/castget/conffiles
/opt/etc/castgetrc
endef

define Package/castget/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/castget $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/castgetrc.example $(1)/opt/etc/castgetrc
endef

$(eval $(call BuildPackage,castget))
