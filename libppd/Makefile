# SPDX-License-Identifier: Apache-2.0
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=libppd
PKG_VERSION:=2.1.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/OpenPrinting/libppd/releases/download/$(PKG_VERSION)
PKG_HASH:=3fa341cc03964046d2bf6b161d80c1b4b2e20609f38d860bcaa11cb70c1285e4

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libppd
	SECTION:=libs
	CATEGORY:=Libraries
	SUBMENU:=Printing
	DEPENDS:=+libcups +libcupsfilters +zlib +libstdcpp $(ICONV_DEPENDS)
	TITLE:=OpenPrinting PPD support library
	URL:=https://github.com/OpenPrinting/libppd
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libppd/description
 libppd provides legacy PostScript Printer Description support.
endef

CONFIGURE_ARGS += \
	--with-cups-config=$(STAGING_DIR)/opt/bin/cups-config \
	--with-cups-rundir=/opt/var/run/cups \
	--disable-testppdfile \
	--disable-ppdc-utils \
	--disable-genstrings \
	--enable-ghostscript \
	--with-gs-path=/opt/bin/gs \
	--with-pdftops=gs \
	--disable-pdftops \
	--disable-mutool \
	--disable-pdftocairo \
	--disable-acroread

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include/ppd
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ppd/*.h $(1)/opt/include/ppd
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libppd.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libppd.pc $(1)/opt/lib/pkgconfig
	$(INSTALL_DIR) $(1)/opt/share/ppdc
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppdc/* $(1)/opt/share/ppdc
endef

define Package/libppd/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libppd.so.* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/ppdc
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppdc/* $(1)/opt/share/ppdc
endef

$(eval $(call BuildPackage,libppd))
