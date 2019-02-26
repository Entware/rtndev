#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libebml
PKG_VERSION:=1.3.6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://dl.matroska.org/downloads/libebml
PKG_HASH:=1e5a7a7820c493aa62b0f35e15b4233c792cc03458c55ebdfa7a6521e4b43e9e

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libebml
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=Extensible Binary Meta Language access library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libebml/description
 libEBML - Extensible Binary Meta Language access library
endef

CMAKE_OPTIONS += -DBUILD_SHARED_LIBS=YES

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ebml $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cmake $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libebml.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libebml/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libebml.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libebml))
