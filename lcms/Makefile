#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=lcms
PKG_VERSION:=2.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)2-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=48c6fdf98396fa245ed86e622028caf49b96fa22f3e5734f853f806fbc8e7d20

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
