#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Based on https://github.com/FranciscoBorges/openwrt-printing-packages

include $(TOPDIR)/rules.mk

PKG_NAME:=ghostscript
PKG_VERSION:=9.27
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs927
PKG_HASH:=9760e8bdd07a08dbd445188a6557cb70e60ccb6a5601f7dbfba0d225e28ce285

PKG_BUILD_DEPENDS:=ghostscript/host
PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/ghostscript
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+fontconfig +libidn +libtiff +libcups
	TITLE:=interpreter for the PostScript language and for PDF
	URL:=https://www.ghostscript.com/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ghostscript/description
 An interpreter for the PostScript language and for PDF.
endef

GS_AUX_BINARIES:=echogs genarch genconf mkromfs packps

HOST_CONFIGURE_ARGS += \
	--disable-fontconfig \
	--disable-dbus \
	--disable-freetype \
	--disable-fapi \
	--disable-cups \
	--disable-openjpeg \
	--disable-gtk \
	--without-x \
	--with-libiconv=no \
	--without-libidn \
	--without-libpaper \
	--without-libtiff \
	--without-pdftoraster \
	--without-ijs \
	--without-luratech \
	--without-jbig2dec \
	--with-drivers=PS

define Host/Compile
	$(foreach binary,$(GS_AUX_BINARIES),
		$(call Host/Compile/Default,obj/aux/$(binary))
	)
endef

define Host/Install
endef

CONFIGURE_ARGS += \
	--with-arch_h=$(PKG_BUILD_DIR)/arch/$(ARCH)-arch.h \
	--with-system-libtiff \
	--with-fontpath=/opt/share/fonts/ghostscript/fonts/:/opt/share/fonts/default/ghostscript/:/opt/share/fonts/default/TrueType/:/opt/share/fonts/default/Type1:/opt/share/cups/fonts/:/opt/share/fonts/ \

define Build/Configure
	(cd $(PKG_BUILD_DIR) && $(RM) -r jpeg libpng zlib)
	$(call Build/Configure/Default)
	mkdir -p $(PKG_BUILD_DIR)/obj/aux
	for binary in $(GS_AUX_BINARIES); do \
		$(CP) $(HOST_BUILD_DIR)/obj/aux/$$$${binary} \
			$(PKG_BUILD_DIR)/obj/aux/$$$${binary}; \
		touch $(PKG_BUILD_DIR)/obj/aux/$$$${binary}; \
	done
endef

define Package/ghostscript/install
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ghostscript $(1)/opt/share
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,ghostscript))
