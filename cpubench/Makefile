#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cpubench
PKG_VERSION:=0.6
PKG_RELEASE:=2

include $(INCLUDE_DIR)/package.mk

define Package/cpubench
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=CPU tools
	TITLE:=OpenWRT's CPU Benchmark
	URL:=http://wl500g.info/showthread.php?30444-%D1%F0%E0%E2%ED%E5%ED%E8%E5-%EF%F0%EE%E8%E7%E2%EE%E4%E8%F2%E5%EB%FC%ED%EE%F1%F2%E8-%EF%F0%EE%F6%E5%F1%F1%EE%F0%EE%E2-%F0%EE%F3%F2%E5%F0%EE%E2
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/cpubench/description
 OpenWRT's CPU Benchmark utility.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/openwrt_cpu_bench_v06.c $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(TARGET_CC) -O0 -c -o $(PKG_BUILD_DIR)/cpubench.o $(PKG_BUILD_DIR)/openwrt_cpu_bench_v06.c
	$(TARGET_CC) -o $(PKG_BUILD_DIR)/cpubench $(PKG_BUILD_DIR)/cpubench.o
endef

define Package/cpubench/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cpubench $(1)/opt/bin
endef

$(eval $(call BuildPackage,cpubench))
