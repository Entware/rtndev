#
# Copyright (C) 2007 OpenWrt
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rblibtorrent
PKG_VERSION:=1.1.14
PKG_RELEASE:=3a

PKG_SOURCE:=libtorrent-rasterbar-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/arvidn/libtorrent/releases/download/libtorrent-$(subst .,_,$(PKG_VERSION))
PKG_HASH:=244f0f189ba8ab9801e7fcf553beebfb83d7c86b

PKG_BUILD_DIR:=$(BUILD_DIR)/libtorrent-rasterbar-$(PKG_VERSION)

CMAKE_INSTALL:=1
PYTHON3_PKG_BUILD:=0

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/rblibtorrent
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=Rasterbar BitTorrent library
  URL:=http://www.rasterbar.com/products/libtorrent/
  DEPENDS:=+boost-chrono +boost-python3 +boost-random +boost-system +libopenssl \
	+python3-light $(ICONV_DEPENDS) $(INTL_DEPENDS)
endef

define Package/rblibtorrent/description
Rasterbar libtorrent is a C++ library that aims to be a good alternative to
all the other bittorrent implementations around. It is a library and not a
full featured client, although it comes with a working example client.
endef

TARGET_CXXFLAGS += -DBOOST_BIND_GLOBAL_PLACEHOLDERS

TARGET_LDFLAGS += $(if $(INTL_FULL),-liconv) $(if $(INTL_FULL),-lintl)

CMAKE_OPTIONS += \
	-Dpython-bindings:BOOL=ON \
	-DPYTHON_EXECUTABLE:FILEPATH=$(STAGING_DIR_HOSTPKG)/bin/python$(PYTHON3_VERSION) \
	-DPYTHON_SITE_PACKAGES="/opt/lib/python$(PYTHON3_VERSION)/site-packages" \
	-DPYTHON_EXT_SUFFIX=""

define Package/rblibtorrent/install
	$(INSTALL_DIR) $(1)/opt/lib/python$(PYTHON3_VERSION)/site-packages
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/python$(PYTHON3_VERSION)/site-packages/*.so* $(1)/opt/lib/python$(PYTHON3_VERSION)/site-packages
endef

$(eval $(call BuildPackage,rblibtorrent))
