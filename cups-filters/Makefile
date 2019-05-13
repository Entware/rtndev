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
PKG_VERSION:=1.22.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/OpenPrinting/cups-filters/releases/download/release-1-22-5
PKG_HASH:=eb37ce1d64352564216580e8bb1b23b3005563cdd8d207141ae1049afaefb4eb

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/cups-filters
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libpoppler +qpdf +glib2 +libdbus +dejavu-fonts-ttf-DejaVuSans +dejavu-fonts-ttf-DejaVuSansMono
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
	--with-test-font-path=/opt/share/fonts/ttf-dejavu/DejaVuSans.ttf \
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
endef

define Package/cups-filters/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) \
	    $(PKG_INSTALL_DIR)/opt/etc/cups/cups-browsed.conf \
	    $(1)/opt/etc/cups
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cups $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-browsed $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/share/cups
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ppd $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups/{charsets,data,drv,mime,ppdc} \
	    $(1)/opt/share/cups
endef

$(eval $(call BuildPackage,cups-filters))
