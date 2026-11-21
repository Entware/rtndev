# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Entware
#
# QEMU 11 dropped 32-bit build hosts and 11.1 requires GCC 10.4.

include $(TOPDIR)/rules.mk

PKG_NAME:=qemu-ga
PKG_VERSION:=10.2.4
PKG_RELEASE:=1

PKG_SOURCE:=qemu-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/qemu/qemu/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=b3d8e8ed4d34ddba38c388a8da294ed71fa6e6f84e07a7da333e5ab4a6955802

PKG_BUILD_DIR:=$(BUILD_DIR)/qemu-ga-$(PKG_VERSION)
PKG_UNPACK=$(HOST_TAR) -xzf $(DL_DIR)/$(PKG_SOURCE) --strip-components=1 -C $(PKG_BUILD_DIR)

PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING

PKG_BUILD_DEPENDS:=python3/host python-setuptools/host python-wheel/host
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/nls.mk
include $(INCLUDE_DIR)/package.mk

KEYCODEMAPDB_VERSION:=f5772a62ec52591ff6870b7e8ef32482371f22c6
KEYCODEMAPDB_SOURCE:=keycodemapdb-$(KEYCODEMAPDB_VERSION).tar.gz

define Download/keycodemapdb
	FILE:=$(KEYCODEMAPDB_SOURCE)
	URL:=https://codeload.github.com/qemu/keycodemapdb/tar.gz/$(KEYCODEMAPDB_VERSION)?
	HASH:=d014b53382dbb17b8196ad12f50de7f20d0ef1b9f7d54b0be51a6cbb14209195
endef

$(eval $(call Download,keycodemapdb))

define Package/qemu-ga
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=QEMU Guest Agent
	URL:=https://www.qemu.org/
	DEPENDS:=+glib2 +libpthread +librt $(ICONV_DEPENDS) $(INTL_DEPENDS)
endef

define Package/qemu-ga/description
 The QEMU Guest Agent is a daemon intended to be run within virtual machines.
 It allows the hypervisor host to perform various operations in the guest.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/subprojects/keycodemapdb
	$(HOST_TAR) -xzf $(DL_DIR)/$(KEYCODEMAPDB_SOURCE) --strip-components=1 \
		-C $(PKG_BUILD_DIR)/subprojects/keycodemapdb
endef

define Build/Configure
	$(INSTALL_DIR) $(PKG_BUILD_DIR)/entware-build
	(cd $(PKG_BUILD_DIR)/entware-build && ../configure \
		--prefix=/opt \
		--sysconfdir=/opt/etc \
		--localstatedir=/opt/var \
		--cross-prefix="$(TARGET_CROSS)" \
		--python="$(STAGING_DIR_HOSTPKG)/bin/python3" \
		--extra-cflags="$(TARGET_CPPFLAGS) $(TARGET_CFLAGS)" \
		--extra-ldflags="$(TARGET_LDFLAGS)" \
		--without-default-features \
		--disable-download \
		--disable-system \
		--disable-user \
		--disable-tools \
		--disable-tcg \
		--disable-docs \
		--enable-guest-agent \
		--target-list=)
endef

define Build/Compile
	+$(NINJA) -C $(PKG_BUILD_DIR)/entware-build qemu-ga
endef

define Package/qemu-ga/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/entware-build/qga/qemu-ga $(1)/opt/bin/
endef

$(eval $(call BuildPackage,qemu-ga))
