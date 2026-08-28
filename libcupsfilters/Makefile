# SPDX-License-Identifier: Apache-2.0
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=libcupsfilters
PKG_VERSION:=2.2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/OpenPrinting/libcupsfilters/releases/download/$(PKG_VERSION)
PKG_HASH:=0a22b849d5068c4c86b20fbb4192d3faa3dabcc9ee844c8fd73710ed821d4860

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libcupsfilters
	SECTION:=libs
	CATEGORY:=Libraries
	SUBMENU:=Printing
	DEPENDS:=+libcups +lcms +pdfio $(ICONV_DEPENDS)
	TITLE:=OpenPrinting CUPS filters library
	URL:=https://github.com/OpenPrinting/libcupsfilters
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libcupsfilters/description
 libcupsfilters provides common functions used by OpenPrinting filters.
endef

CONFIGURE_ARGS += \
	--with-cups-config=$(STAGING_DIR)/opt/bin/cups-config \
	--with-cups-rundir=/opt/var/run/cups \
	--disable-imagefilters \
	--without-jpeg \
	--without-png \
	--without-tiff \
	--without-jpegxl \
	--disable-exif \
	--without-fontconfig \
	--disable-texttopdf \
	--disable-dbus \
	--disable-ghostscript \
	--disable-mutool

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include/cupsfilters
	$(CP) $(PKG_INSTALL_DIR)/opt/include/cupsfilters/*.h $(1)/opt/include/cupsfilters
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libcupsfilters.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libcupsfilters.pc $(1)/opt/lib/pkgconfig
endef

define Package/libcupsfilters/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libcupsfilters.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libcupsfilters))
