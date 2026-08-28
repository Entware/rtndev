# SPDX-License-Identifier: Apache-2.0
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=pdfio
PKG_VERSION:=1.6.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/michaelrsweet/pdfio/releases/download/v$(PKG_VERSION)
PKG_HASH:=2b9e1db7c4a72cbc896098a6682a1e51fc2bfb979f00bec8bb515ee79c338084

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/pdfio
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+zlib +libpng
	TITLE:=PDF read and write library
	URL:=https://www.msweet.org/pdfio/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pdfio/description
 PDFio is a C library for reading and writing PDF files.
endef

CONFIGURE_ARGS += \
	--enable-shared \
	--disable-static \
	--enable-libpng

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/pdfio*.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpdfio.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/pdfio.pc $(1)/opt/lib/pkgconfig
endef

define Package/pdfio/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpdfio.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,pdfio))
