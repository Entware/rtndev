#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Compiled with the help of following sources:
#	* http://github.com/FranciscoBorges/openwrt-printing-packages
#	* http://code.google.com/p/pits/source/browse/trunk/ijsgutenprint/Makefile

include $(TOPDIR)/rules.mk

PKG_NAME:=gutenprint
PKG_VERSION:=5.2.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/gimp-print
PKG_HASH:=d9a9745d83668096e89e762e380b40629ea2dcb44a1b7027b9068c543cd02742

PKG_BUILD_DEPENDS:=gutenprint/host cups libiconv
HOST_BUILD_DEPENDS:=libiconv/host
PKG_INSTALL:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/gutenprint
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libcupsimage $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=Gutenprint CUPS drivers
	URL:=http://gimp-print.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/gutenprint/description
 Gutenprint CUPS drivers for a wide range of Canon, Epson, HP and
 compatible printers.
endef

CONFIGURE_ARGS += \
	--disable-test \
	--without-doc \
	--without-readline \
	--without-foomatic \
	--without-foomatic3 \
	--enable-escputil=no \
	--enable-test=no \
	--disable-translated-cups-ppds \
	--disable-globalized-cups-ppds \
	--enable-simplified-cups-ppds \
	--bindir=/opt/bin \
	--sbindir=/opt/bin \
	--prefix=/opt \
	--exec-prefix=/opt

define Build/Compile
	# Replace the cross-compiled "extract-string" by a shell-script that
	# runs the host's own compiled version (gutenprint needs to run this)
	(cd $(PKG_BUILD_DIR) && $(MAKE) -C src/xml extract-strings && \
	$(RM) src/xml/extract-strings && \
	echo '#!/bin/sh' > src/xml/extract-strings && \
	echo 'exec $(HOST_BUILD_DIR)/src/xml/extract-strings  "$$$$@" ' \
	>> src/xml/extract-strings && chmod +x src/xml/extract-strings && cp src/xml/extract-strings /tmp/)
	$(call Build/Compile/Default)
endef

define Package/gutenprint/install
	$(INSTALL_DIR) $(1)/opt/sbin $(1)/opt/bin
	# XXX Do not install cups-genppdupdate, as it requires Perl + some perl libs
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/cups-genppd.[0-9]*.[0-9]* $(1)/opt/sbin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cups-calibrate $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/lib/cups/{driver,filter}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/cups/driver/gutenprint.* $(1)/opt/lib/cups/driver
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/cups/filter/* $(1)/opt/lib/cups/filter
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libgutenprint.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/cups/mime
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/cups/command.types $(1)/opt/share/cups/mime
	$(INSTALL_DIR) $(1)/opt/share/gutenprint
	$(CP) $(PKG_INSTALL_DIR)/opt/share/gutenprint/[0-9]*.[0-9]* $(1)/opt/share/gutenprint
endef

define Host/Compile
	$(MAKE) $(HOST_JOBS) -C $(HOST_BUILD_DIR)/src/xml $(HOST_MAKE_FLAGS) extract-strings
endef

define Host/Install
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,gutenprint))
