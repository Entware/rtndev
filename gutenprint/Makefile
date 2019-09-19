#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Based on https://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=gutenprint
PKG_VERSION:=5.3.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=@SF/gimp-print
PKG_HASH:=7279ecbc8e67d1858c53cb24e423ea1be98e214872006b79e6e03650dd54a072

PKG_BUILD_DEPENDS:=gutenprint/host
PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/gutenprint
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libreadline +libncursesw
	TITLE:=Gutenprint CUPS drivers
	URL:=http://gimp-print.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/gutenprint/description
 High quality drivers for Canon, Epson, Lexmark, Sony, Olympus, and PCL
 printers for use with CUPS and GIMP.
endef

define Host/Patch
endef

HOST_CONFIGURE_ARGS += \
	--disable-shared \
	--disable-nls \
	--disable-nls-macosx \
	--disable-samples \
	--disable-escputil \
	--disable-test \
	--without-cups \
	--without-modules \
	--without-readline \
	--without-gimp2 \
	--without-doc

define Host/Compile
	$(MAKE) $(HOST_JOBS) -C $(HOST_BUILD_DIR)/src/xml/printers $(HOST_MAKE_FLAGS) check_duplicate_printers.test
	$(MAKE) $(HOST_JOBS) -C $(HOST_BUILD_DIR)/src/xml $(HOST_MAKE_FLAGS) extract-strings
endef

define Host/Install
endef

CONFIGURE_ARGS += \
	--disable-test

define Build/Configure
	$(call Build/Configure/Default)
	ln -s $(HOST_BUILD_DIR)/src/xml/printers/check_duplicate_printers.test \
		$(PKG_BUILD_DIR)/src/xml/printers/check_duplicate_printers.test
	ln -s $(HOST_BUILD_DIR)/src/xml/extract-strings \
		$(PKG_BUILD_DIR)/src/xml/extract-strings
endef

define Package/gutenprint/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cups $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libgutenprint.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-genppd.5.3 $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/share/gutenprint
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/gutenprint/5.3 $(1)/opt/share/gutenprint
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,gutenprint))
