#
# Copyright (C) 2011-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
include $(TOPDIR)/rules.mk

PKG_NAME:=splix
PKG_VERSION:=2.0.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://github.com/OpenPrinting/splix/releases/download/$(PKG_VERSION)
PKG_HASH:=6271c35f8ab8d2565962c0a6140aa191226430f7c99cb3355f4d499a8938f068

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/splix
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Printing
	DEPENDS:=+cups +libjbig
	TITLE:=Samsung CUPS drivers
	URL:=https://openprinting.github.io/splix/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/splix/description
 SpliX is a set of CUPS printer drivers for SPL (Samsung Printer Language)
 printers.
endef

MAKE_VARS += \
	THREADS=1 \
	DRV_ONLY=1 \
	CUPSFILTER=/opt/lib/cups/filter \
	CUPSPPD=/opt/share/cups/model \
	CUPSDRV=/opt/share/cups/drv \
	CUPSPROFILE=/opt/share/cups/profiles

TARGET_LDFLAGS += \
	-Wl,-rpath-link=$(STAGING_DIR)/opt/lib/libiconv-full/lib \
	-Wl,-rpath-link=$(STAGING_DIR)/opt/lib/libintl-full/lib

define Build/Configure
	$(MAKE) -C $(PKG_BUILD_DIR)/ppd drv
endef
define Package/splix/install
	$(INSTALL_DIR) $(1)/opt/lib/cups/filter
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/filter/{raster,ps}toqpdl \
	    $(1)/opt/lib/cups/filter
	$(INSTALL_DIR) $(1)/opt/share/cups/drv
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cups/drv/* $(1)/opt/share/cups/drv
endef

$(eval $(call BuildPackage,splix))
