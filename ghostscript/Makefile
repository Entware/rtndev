#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Based on https://github.com/FranciscoBorges/openwrt-printing-packages
#
# 9.51-9.52 trying to use freetype even if it explicitly disabled

include $(TOPDIR)/rules.mk

PKG_NAME:=ghostscript
PKG_VERSION:=9.50
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs$(subst .,,$(PKG_VERSION))
PKG_HASH:=0f53e89fd647815828fc5171613e860e8535b68f7afbc91bf89aee886769ce89

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

GS_AUX_BINARIES:=echogs genarch genconf packps

HOST_CONFIGURE_ARGS += \
	--without-libtiff \
	--disable-contrib \
	--disable-fontconfig \
	--disable-dbus \
	--disable-freetype \
	--disable-fapi \
	--disable-cups \
	--disable-openjpeg \
	--disable-gtk \
	--with-libiconv=no \
	--without-libidn \
	--without-libpaper \
	--without-pdftoraster \
	--without-ijs \
	--without-luratech \
	--without-jbig2dec \
	--without-x \
	--with-drivers=""

define Host/Compile
	$(foreach binary,$(GS_AUX_BINARIES),
		$(call Host/Compile/Default,obj/aux/$(binary))
	)
endef

define Host/Install
endef

CONFIGURE_ARGS += \
	--with-arch_h=$(PKG_BUILD_DIR)/arch/$(ARCH)-arch.h \
	--disable-compile-inits \
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

define Build/Install
	$(call Build/Install/Default)
	$(call Build/Install/Default,install-examples)
endef

define Package/ghostscript/install
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/share/ghostscript $(1)/opt/share
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,ghostscript))
