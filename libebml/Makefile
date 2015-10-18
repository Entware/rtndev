#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libebml
PKG_VERSION:=1.3.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://dl.matroska.org/downloads/libebml
PKG_MD5SUM:=2d5a0e502fabedfded2a890c6b5513a5

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libebml
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=Extensible Binary Meta Language access library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/libebml/description
 libEBML - Extensible Binary Meta Language access library
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ebml $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.{a,la,so*} $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libebml.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libebml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libebml))
