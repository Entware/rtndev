#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mkvtoolnix
PKG_VERSION:=33.1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://mkvtoolnix.download/sources
PKG_HASH:=c077f4563fe76e09799fca2451464e0d2d0ebf0e17d1b1b179ec735b19fe6f2a

PKG_BUILD_DEPENDS:=ruby/host

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mkvtoolnix
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+boost-filesystem +boost-regex +libbz2 +libexpat +libflac \
		+liblzo +libmagic +libmatroska +libvorbis \
		$(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=tools for Matroska files
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mkvtoolnix/description
 A set of tools to create, alter and inspect Matroska files.
endef

CONFIGURE_ARGS += \
	--disable-gui \
	--disable-static \
	--with-boost=$(STAGING_DIR)/opt \
	--without-curl \
	--without-gettext \

TARGET_LDFLAGS += \
	-lstdc++ \
	-lintl \

define Build/Compile
	cd $(PKG_BUILD_DIR); rake --jobs=1
endef

define Package/mkvtoolnix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/mkv{extract,info,merge,propedit} \
		$(1)/opt/bin
endef

$(eval $(call BuildPackage,mkvtoolnix))
