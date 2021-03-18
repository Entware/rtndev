#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lcms
PKG_VERSION:=2.12
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)2-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=18663985e864100455ac3e507625c438c3710354d85e5cbb7cd4043e11fe10f5

PKG_INSTALL:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)2-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/lcms
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+libtiff +libpthread
	TITLE:=little CMS color engine
	URL:=http://www.littlecms.com/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/lcms/description
 Little CMS color engine.
endef

define Package/lcms/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/*icc $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/liblcms2.so* $(1)/opt/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/lcms2.pc $(1)/opt/lib/pkgconfig
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/lcms2*.h $(1)/opt/include
endef

$(eval $(call BuildPackage,lcms))
