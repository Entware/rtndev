#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-filters
PKG_VERSION:=1.22.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/OpenPrinting/cups-filters/releases/download/release-1-22-1
PKG_HASH:=a51577ae95dc61a4100cdee38a2bf271bc4bfa80c7cda71bc4807f883c0b39bc

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-filters
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libpoppler +qpdf +glib2 +libdbus
	TITLE:=OpenPrinting CUPS filters
	URL:=http://www.openprinting.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cups-filters/description
 CUPS filters maintained by OpenPrinting. The CUPS Filters package contains
 backends, filters and other software that was once part of the core CUPS
 distribution but is no longer maintained by Apple Inc.
endef

CONFIGURE_ARGS += \
	--disable-opvp \
	--disable-avahi \
	--disable-ldap \
	--disable-braille \
	--with-pdftops=gs \
	--with-gs-path=/opt/bin/gs \
	--with-pdftops-path=/opt/bin/gs \
	--with-test-font-path=/opt/share/fonts/dejavu/DejaVuSans.ttf \
	--with-shell=/bin/sh

CONFIGURE_VARS += \
	LIBQPDF_CFLAGS=-I$(STAGING_DIR)/opt/include \
	LIBQPDF_LIBS=-L$(STAGING_DIR)/opt/lib \
	POPPLER_CFLAGS=-I$(STAGING_DIR)/opt/include/poppler \
	POPPLER_LIBS=-L$(STAGING_DIR)/opt/lib

TARGET_CXXFLAGS += -std=c++0x
TARGET_LDFLAGS += -liconv -lqpdf -lpoppler

define Package/cups-filters/conffiles
/opt/etc/cups/cups-browsed.conf
/opt/etc/fonts/conf.d/99pdftoopvp.conf
endef

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/cups/cups-browsed.conf \
	    $(1)/opt/etc/cups
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cups $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-browsed $(1)/opt/sbin
endef

$(eval $(call BuildPackage,cups-filters))
