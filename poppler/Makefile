#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
# The newer versions requires openjpeg https://github.com/uclouvain/openjpeg

include $(TOPDIR)/rules.mk

PKG_NAME:=poppler
PKG_VERSION:=0.53.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://poppler.freedesktop.org
PKG_HASH:=592bf72960c6b5948b67657594b05e72d9a278daf7613c9f3cdff9a5b73096a8

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libpoppler
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+fontconfig +lcms +libpng +libtiff +libstdcpp
	TITLE:=Poppler PDF rendering library
	URL:=https://poppler.freedesktop.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/poppler-utils
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libpoppler
	TITLE:=Poppler PDF rendering utilities
	URL:=https://poppler.freedesktop.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libpoppler/description
 Poppler is a PDF rendering library based on the xpdf-3.0.
endef

define Package/poppler-utils/description
 Poppler is a PDF rendering utilities based on the xpdf-3.0.
endef

CONFIGURE_ARGS += \
	--enable-xpdf-headers \
	--enable-gtk-doc-html \
	--enable-cms=lcms2 \
	--with-font-configuration=fontconfig \

define Package/libpoppler/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpoppler.so* $(1)/opt/lib
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/poppler $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpoppler.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/poppler*.pc $(1)/opt/lib/pkgconfig
endef

define Package/poppler-utils/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/pdf* $(1)/opt/bin
endef

$(eval $(call BuildPackage,libpoppler))
$(eval $(call BuildPackage,poppler-utils))
