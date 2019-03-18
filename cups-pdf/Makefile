#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cups-pdf
PKG_VERSION:=3.0.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.cups-pdf.de/src
PKG_HASH:=738669edff7f1469fe5e411202d87f93ba25b45f332a623fb607d49c59aa9531

include $(INCLUDE_DIR)/package.mk

define Package/cups-pdf
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Printing
	DEPENDS:=+ghostscript +libcups
	TITLE:=PDF printer software
	URL:=http://www.cups-pdf.de/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cups-pdf/description
 This software is designed to produce PDF files in a heterogeneous network by providing a PDF printer
 on the central fileserver.
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(STAGING_DIR)/opt/include -I./src \
		$(TARGET_LDFLAGS) $(PKG_BUILD_DIR)/src/cups-pdf.c -s -lcups \
		-o $(PKG_BUILD_DIR)/$(PKG_NAME)
endef

define Package/cups-pdf/conffiles
/opt/etc/cups/cups-pdf.conf
endef

define Package/cups-pdf/install
	$(INSTALL_DIR) $(1)/opt/lib/cups/backend
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cups-pdf $(1)/opt/lib/cups/backend
	$(INSTALL_DIR) $(1)/opt/share/cups/model/generic
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/extra/CUPS-PDF_{opt,noopt}.ppd \
		$(1)/opt/share/cups/model/generic
	$(INSTALL_DIR) $(1)/opt/etc/cups
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/extra/cups-pdf.conf $(1)/opt/etc/cups
endef

$(eval $(call BuildPackage,cups-pdf))
