# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware
# Copyright (C) 2013 Francisco Borges

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-filters
PKG_VERSION:=2.0.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/OpenPrinting/cups-filters/releases/download/$(PKG_VERSION)
PKG_HASH:=39e71de3ce06762b342749f1dc7cba6817738f7bf4d322c1bb9ab10b8569ab80

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-filters
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libcupsfilters +libppd +libstdcpp $(ICONV_DEPENDS) \
		+dejavu-fonts-ttf-DejaVuSans +dejavu-fonts-ttf-DejaVuSansMono
	TITLE:=OpenPrinting CUPS filters
	URL:=https://openprinting.github.io/cups-filters/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cups-filters/description
 CUPS filters maintained by OpenPrinting.
endef

CONFIGURE_ARGS += \
	--with-cups-config=$(STAGING_DIR)/opt/bin/cups-config \
	--enable-imagefilters \
	--enable-poppler \
	--enable-ghostscript \
	--with-gs-path=/opt/bin/gs \
	--disable-mutool \
	--enable-driverless \
	--enable-foomatic \
	--enable-universal-cups-filter \
	--disable-individual-cups-filters \
	--with-ippfind-path=/opt/bin/ippfind \
	--with-shell=/bin/sh

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/opt/lib/cups
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cups/{backend,driver,filter} $(1)/opt/lib/cups
	$(INSTALL_DIR) $(1)/opt/share/cups
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups/{drv,mime} $(1)/opt/share/cups
	$(INSTALL_DIR) $(1)/opt/share/ppd
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppd/* $(1)/opt/share/ppd
	$(INSTALL_DIR) $(1)/opt/share/ppdc
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppdc/* $(1)/opt/share/ppdc
endef

$(eval $(call BuildPackage,cups-filters))
