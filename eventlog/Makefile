#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=eventlog
PKG_VERSION:=0.2.12
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://my.balabit.com/downloads/eventlog/0.2
PKG_MD5SUM:=3d6ebda8a161d36cb40d09328f78786b

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/eventlog
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Extensible Binary Meta Language access library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/eventlog/description
 eventlog - Extensible Binary Meta Language access library
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/eventlog $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libevtlog.{a,la,so*} $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/eventlog.pc $(1)/opt/lib/pkgconfig/
endef

define Package/eventlog/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libevtlog.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,eventlog))
