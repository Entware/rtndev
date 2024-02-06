#
# Copyright (C) 2013 Francisco Borges
# Copyright (C) 2011-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
# 21.12.0+ requires GCC 9.4.0

include $(TOPDIR)/rules.mk

PKG_NAME:=poppler
PKG_VERSION:=21.08.0
PKG_RELEASE:=4

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://poppler.freedesktop.org
PKG_HASH:=e9cf5dc5964bce4bb0264d1c4f8122706c910588b421cfc30abc97d6b23e602d

PKG_BUILD_DEPENDS:=boost

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libpoppler
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+fontconfig +lcms +libpng +libtiff +libstdcpp $(ICONV_DEPENDS)
	TITLE:=Poppler PDF rendering library
	URL:=https://poppler.freedesktop.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/poppler-utils
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libpoppler
	TITLE:=Poppler PDF rendering utilities
	URL:=https://poppler.freedesktop.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libpoppler/description
 Poppler is a PDF rendering library based on the xpdf-3.0.
endef

define Package/poppler-utils/description
 Poppler is a PDF rendering utilities based on the xpdf-3.0.
endef

TARGET_CFLAGS += -pthread
TARGET_LDFLAGS += -lpthread

CMAKE_OPTIONS += \
	-DENABLE_LIBCURL=OFF \
	-DENABLE_LIBOPENJPEG=unmaintained \
	-DENABLE_QT5=OFF \
	-DENABLE_UNSTABLE_API_ABI_HEADERS=ON \
	-DENABLE_XPDF_HEADERS=ON \
	-DICONV_INCLUDE_DIR=$(ICONV_PREFIX)/include \
	-DICONV_SECOND_ARGUMENT_IS_CONST=0 \
	-DWITH_NSS3=OFF

define Package/libpoppler/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libpoppler*.so* $(1)/opt/lib
endef

define Package/poppler-utils/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/pdf* $(1)/opt/bin
endef

$(eval $(call BuildPackage,libpoppler))
$(eval $(call BuildPackage,poppler-utils))
