#
# Copyright (C) 2011-2016 Entware
# Copyright (C) 2013 Francisco Borges
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
# Patches should be reworked for newer releases.

include $(TOPDIR)/rules.mk

PKG_NAME:=ghostscript
PKG_VERSION:=9.16
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://downloads.ghostscript.com/public/$(PKG-SOURCE)
PKG_MD5SUM:=829319325bbdb83f5c81379a8f86f38f

PKG_BUILD_DEPENDS:=ghostscript/host
PKG_INSTALL:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/ghostscript
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libcupsimage +libfreetype +fontconfig +libtiff +libjpeg +libpng +libexpat +lcms +zlib +ghostscript-fonts-std +libdbus
	TITLE:=ghostscript interpreter
	URL:=http://gimp-print.sourceforge.net/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/ghostscript/description
 Ghostscript is an interpreter for the PostScript language and for PDF.
endef

TARGET_CFLAGS += -I$(STAGING_DIR)/opt/include/freetype2

HOST_CONFIGURE_ARGS += \
	--without-x \
	--without-jbig2dec \
	--without-pdftoraster \
	--without-libpaper \
	--disable-gtk \
	--without-libidn \

CONFIGURE_ARGS += \
	--enable-little-endian \
	--disable-gtk \
	--without-libidn \
	--without-x \
	--without-jbig2dec \
	--enable-cups \
	--with-fontpath=/opt/share/fonts/ghostscript/fonts/:/opt/share/ghostscript/9.06/Resource/Font/:/opt/share/fonts/default/ghostscript/:/opt/share/fonts/default/TrueType/:/opt/share/fonts/default/Type1:/opt/share/cups/fonts/:/opt/share/fonts/:/opt/share/fonts/ubuntu/:/opt/share/fonts/truetype/liberation/ \
	--with-system-libtiff \
	--with-cups-serverbin=/opt/lib/cups \
	--with-cups-serverroot=/opt/etc/cups \
	--with-cups-datadir=/opt/share/cups \

define Build/Configure
	(cd $(PKG_BUILD_DIR) && $(RM) -r jpeg expat jasper freetype lcms2 lcms libpng tiff zlib)
	$(call Build/Configure/Default)
endef

define Build/Compile
	# base/unix-aux.mak is patched, and now we replace these fixed strings by the actual paths.
	# PS. doing all in sed would be painful because the commands would need too much escaping.
	$(SED) 's,OPENWRT_BASE_BUILD_PATH,$(HOST_BUILD_DIR),g' $(PKG_BUILD_DIR)/base/unix-aux.mak
	$(SED) 's,OPENWRT_PGK_BUILD_PATH,$(PKG_BUILD_DIR),g' $(PKG_BUILD_DIR)/base/unix-aux.mak
	$(SED) 's,/usr/include,$(TOOLCHAIN_DIR)/include,g' $(PKG_BUILD_DIR)/base/unix-aux.mak
	$(SED) 's,-I/usr/include,-I$(TOOLCHAIN_DIR)/include,g' $(PKG_BUILD_DIR)/base/all-arch.mak
	$(call Build/Compile/Default, cross_prepare)
	$(call Build/Compile/Default)
endef

# Patches cannot be applied to the host build
define Host/Patch
endef

# No need to install or patch HOST
define Host/Install
	$(LN) $(HOST_BUILD_DIR)/obj/aux/mkromfs $(HOST_BUILD_DIR)/obj/aux/mkromfs_1
endef

define Package/ghostscript/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	#--------------------------------------------------------------
	# Unlike what
	# http://ghostscript.com/doc/9.06/Use.htm#Finding_files states
	# GS is /not/ taking the first dir of GS_LIB_DEFAULT (perhaps
	# because it does not exist in my system?). The solution in
	# place is to replace 'gs' by a script that sets GS_LIB
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/gs $(1)/opt/bin/gs.orig
	$(RM) $(1)/opt/bin/gs
	$(CP) ./files/gs $(1)/opt/bin/
	#--------------------------------------------------------------
	$(INSTALL_DIR) $(1)/opt/share/ghostscript/$(PKG_VERSION)/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/ghostscript/$(PKG_VERSION)/lib/* \
	        $(1)/opt/share/ghostscript/$(PKG_VERSION)/lib
	$(CP) -r $(PKG_BUILD_DIR)/Resource $(1)/opt/share/ghostscript/$(PKG_VERSION)/
	$(CP) -r $(PKG_BUILD_DIR)/iccprofiles $(1)/opt/share/ghostscript/$(PKG_VERSION)/
	# $(INSTALL_DIR) $(1)/opt/share/ghostscript/$(PKG_VERSION)/examples/cjk
	$(CP) -r $(PKG_INSTALL_DIR)/opt/share/ghostscript/$(PKG_VERSION)/examples \
	    $(1)/opt/share/ghostscript/$(PKG_VERSION)/examples
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,ghostscript))
