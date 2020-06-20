#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mkvtoolnix
PKG_VERSION:=47.0.0
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://mkvtoolnix.download/sources
PKG_HASH:=8b7744203758025585b28200906c4b85716a6b1b95fed77cc520f9ae59c2ae44

PKG_FIXUP:=autoreconf
PKG_BUILD_DEPENDS:=ruby/host pugixml libmatroska 

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mkvtoolnix
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+boost-filesystem +boost-regex +libbz2 +libexpat +libflac \
		+liblzo +libmagic +libvorbis +libfmt \
		$(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=tools for Matroska files
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mkvtoolnix/description
 A set of tools to create, alter and inspect Matroska files.
endef

CONFIGURE_ARGS += \
	--disable-static \
	--disable-qt \
	--with-boost=$(STAGING_DIR)/opt \
	--without-qt-pkg-config \
	--without-moc \
	--without-uic \
	--without-rcc \
	--without-qmake

TARGET_CFLAGS += -Wno-logical-op

TARGET_LDFLAGS += \
	-lstdc++ \
	-lintl

define Build/Compile
	cd $(PKG_BUILD_DIR); rake
endef

define Package/mkvtoolnix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/mkv{extract,info,merge,propedit} \
		$(1)/opt/bin
endef

$(eval $(call BuildPackage,mkvtoolnix))
