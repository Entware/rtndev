# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware
#
# 81.0 is the last release compatible with Qt 5.

include $(TOPDIR)/rules.mk

PKG_NAME:=mkvtoolnix
PKG_VERSION:=81.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://mkvtoolnix.download/sources
PKG_HASH:=422f2bec88d5d93547df0c3e1399272a6dc4c23050b45d34343bbdd6d55e5ad6

PKG_FIXUP:=autoreconf
PKG_BUILD_DEPENDS:=ruby/host pugixml libmatroska

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mkvtoolnix
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+boost-filesystem +libflac +libgmp +libogg +libvorbis \
		+qt5-core +zlib $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=tools for Matroska files
	URL:=https://mkvtoolnix.download/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mkvtoolnix/description
 A set of tools to create, alter and inspect Matroska files.
endef

CONFIGURE_ARGS += \
	--disable-static \
	--disable-gui \
	--disable-qt6 \
	--disable-precompiled-headers \
	--without-dvdread \
	--with-boost=$(STAGING_DIR)/opt \
	--with-qmake=$(TOOLCHAIN_DIR)/bin/qmake

CONFIGURE_VARS += ac_cv_fmt=no

ifeq ($(CONFIG_BUILD_NLS),y)
CONFIGURE_VARS += LIBINTL_LIBS="-lintl"
endif

MKVTOOLS:=mkvextract mkvinfo mkvmerge mkvpropedit

define Build/Compile
	cd $(PKG_BUILD_DIR) && rake $(addprefix src/,$(MKVTOOLS))
endef

define Package/mkvtoolnix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(addprefix $(PKG_BUILD_DIR)/src/,$(MKVTOOLS)) \
		$(1)/opt/bin
endef

$(eval $(call BuildPackage,mkvtoolnix))
